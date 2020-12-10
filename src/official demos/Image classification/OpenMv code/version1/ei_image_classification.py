# Edge Impulse - OpenMV Image Classification Example

import sensor, image, time, os, tf
import pyb, ustruct

sensor.reset()                         # Reset and initialize the sensor.
sensor.set_pixformat(sensor.RGB565)    # Set pixel format to RGB565 (or GRAYSCALE)
sensor.set_framesize(sensor.QVGA)      # Set frame size to QVGA (320x240)
sensor.set_windowing((240, 240))       # Set 240x240 window.
sensor.skip_frames(time=2000)          # Let the camera adjust.

net = "trained.tflite"
labels = [line.rstrip('\n') for line in open("labels.txt")]

clock = time.clock()


text = "This is a test!\n"
data = ustruct.pack("<%ds" % len(text), text)


bus = pyb.I2C(2, pyb.I2C.SLAVE, addr=0x12)
bus.deinit()
bus = pyb.I2C(2, pyb.I2C.SLAVE, addr=0x12)
print("Waiting for Arduino...")


while(True):
    clock.tick()

    img = sensor.snapshot()

    # default settings just do one detection... change them to search the image...
    for obj in tf.classify(net, img, min_scale=1.0, scale_mul=0.8, x_overlap=0.5, y_overlap=0.5):
        print("**********\nPredictions at [x=%d,y=%d,w=%d,h=%d]" % obj.rect())
        img.draw_rectangle(obj.rect())
        # This combines the labels and confidence values into a list of tuples
        predictions_list = list(zip(labels, obj.output()))

        for i in range(len(predictions_list)):
            print("%s = %f" % (predictions_list[i][0], predictions_list[i][1]))

            greenValue = predictions_list[0][1]
            redValue = predictions_list[2][1]
            classifyValueRed = "red"
            classifyValueGreen = "green"


            if(redValue > 0.90):
                print("red")
                try:
                    bus.send(ustruct.pack("<h", len(classifyValueRed)), timeout=10000)
                    try:
                        bus.send(classifyValueRed, timeout=10000)


                        print("Sent Data 1!")
                    except OSError as err:
                        pass
                except OSError as err:
                    pass

            if(greenValue > 0.90):
                print("green")
                try:
                    bus.send(ustruct.pack("<h", len(classifyValueGreen)), timeout=10000)
                    try:
                        bus.send(classifyValueGreen, timeout=10000)


                        print("Sent Data 2!")
                    except OSError as err:
                        pass
                except OSError as err:
                    pass


    print(clock.fps(), "fps")
