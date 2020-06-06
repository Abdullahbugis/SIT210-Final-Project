import smbus
import time
import Adafruit_DHT as dht


address = 0x05
bus = smbus.SMBus(1)

def SendNum(Val):
   bus.write_i2c_block_data(address,0x01,Val)
   return -1


while True:
         time.sleep(5)
         h,t = dht.read_retry(dht.DHT22,4)
         print ('Temprature={0:0.1f}c Humidity={1:0.1f}%'.format(t,h))

         if   t >= 10 and h >= 30:
              SendNum([0])


         elif t < 25 and h < 50:

              SendNum([1])

         else:

              time.sleep(5)
