
latitude_list = []
longitude_list = []

# Tiva-c connected to com port 8 according to the laptop
s = serial.Serial('COM8')
for i in range(0,8):
    data_to_send='U' 
    s.write(data_to_send.encode())
while True:
    readedText = s.readline()
    readedText = readedText.decode("utf-8")
    # Check if reached destination
    if("end" in readedText):

  

    data = readedText.split(',')
    print('Latitude: {0} | Longitude: {1}'.format(data[0], data[1]))
    latitude_list.append(float(data[0]))
    longitude_list.append(float(data[1]))
print("Finished !")
s.close()
