import cv2, serial, pygame, os
import facial_recognition
from time import sleep
from datetime import datetime
from twilio.rest import TwilioRestClient
ACCOUNT_SID = ""
AUTH_TOKEN = ""

client = TwilioRestClient(ACCOUNT_SID, AUTH_TOKEN)

def main():
    pygame.init()
    count = 0;
    screen = pygame.display.set_mode((400,400))
    pygame.display.set_caption('Hi')
    screen.fill((255, 255, 255))
    running = True
    results = []
    again = False
    while(running):
        activated = False
        events = pygame.event.get()
        for event in events:
            if event.type == pygame.MOUSEBUTTONDOWN:
                activated = True
            if event.type == pygame.QUIT:
                running = False
        while(activated):
            print datetime.now()
            sleep(5)
            webcam = cv2.VideoCapture()
            webcam.open(0)
            retval, image = webcam.retrieve()
            webcam.release()
            cv2.imwrite("test{0}.jpg".format(count), image)
            
            x = facial_recognition.check("test{0}.jpg".format(count))

            ser1 = serial.Serial('/dev/tty.usbserial-DA011JAU',9600)
            ser2 = serial.Serial('/dev/tty.usbmodem1431',9600)
            sleep(4.5)
            if x==False:
                ser1.write(str(int(x)))
                ser2.write(str(int(x)))

            results.append(x)
            print results[count]
            if results[count] == False and not again:
                client.messages.create(
                    to="9173286623",
                    from_="+13475274066",
                    body="DO NOT RESPOND TO THIS MESSAGE. An unrecognized person is using your laptop. Login and check who at http://perkt.io/results",
                    ) 
                again = True
            count += 1
            print datetime.now()
            #events = pygame.event.get()
            #for event in events:
                #if event.type == pygame.KEYDOWN:
                    #if event.key == pygame.K_SPACE:
                        #running = False
                        #activated = False
                    
            

if __name__ == "__main__":
      main()          
#for x in os.listdir('./static/images'):
#    os.remove('./static/images/{0}'.format(x))
