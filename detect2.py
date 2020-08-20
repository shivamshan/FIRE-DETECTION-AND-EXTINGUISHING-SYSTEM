import numpy as np
import cv2
import serial
import time
import smtplib 
from email.mime.multipart import MIMEMultipart 
from email.mime.text import MIMEText 
from email.mime.base import MIMEBase 
from email import encoders 
import cv2
   
fromaddr = "SENDERS EMAIL ID"
toaddr = "RECEIVERS EMAIL ID"
   

msg = MIMEMultipart() 
  
  
msg['From'] = fromaddr 
  
  
msg['To'] = toaddr 
  

msg['Subject'] = "Attention"
  

body = "Fire Detected In House"
  

msg.attach(MIMEText(body, 'plain')) 
filename = "pic.jpg"
p = MIMEBase('application', 'octet-stream') 


s = smtplib.SMTP('smtp.gmail.com', 587) 
  

s.starttls() 
  

s.login(fromaddr, "YOUR PASSWORD") 

fire_cascade = cv2.CascadeClassifier('fire_detection.xml')

flag=False

cap = cv2.VideoCapture(0)

while True:
    
    ret, img = cap.read()
    
    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

    fire = fire_cascade.detectMultiScale(img, 1.2, 5)

    for (x,y,w,h) in fire:
        cv2.rectangle(img,(x,y),(x+w,y+h),(0,0,255),2)
        

        print ('Fire is detected..!')
        if flag==False:

            imgencode = cv2.imencode('.jpg', img)[1]

            p.set_payload(imgencode.ravel()) 
  

            encoders.encode_base64(p) 
   
            p.add_header('Content-Disposition', "attachment; filename= %s" % filename) 
  

            msg.attach(p) 
  


  

            text = msg.as_string() 
  

            s.sendmail(fromaddr, toaddr, text)
            s.quit()
            flag=True
        
        
    cv2.imshow('img',img)
    
    
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break

cap.release()
cv2.destroyAllWindows()
