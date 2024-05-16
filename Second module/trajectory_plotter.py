import gmplot
import serial
import folium
import webbrowser

latitude_list = []
longitude_list = []

# Tiva-c connected to com port 3
s = serial.Serial('COM8')
for i in range(0,8):
    data_to_send='U' 
    s.write(data_to_send.encode())
while True:
    readedText = s.readline()
    readedText = readedText.decode("utf-8")
    # Check if reached destination
    if("end" in readedText):
        print(latitude_list)
        print(longitude_list)
        mymap = folium.Map(location=[latitude_list[0], longitude_list[0]], zoom_start=45)
        start_coords = (latitude_list[0], longitude_list[0])
        end_coords = (latitude_list[-1], longitude_list[-1])
        folium.Marker(location=start_coords, popup='Start').add_to(mymap)
        folium.Marker(location=end_coords, popup='End').add_to(mymap)
        num_waypoints = len(latitude_list) - 2  # Exclude start and end coordinates
        for i in range(1, len(latitude_list) - 1):
            folium.CircleMarker(location=(latitude_list[i], longitude_list[i]), radius=0.2, color='blue').add_to(mymap)

        mymap.save(r'map.html')      
        break
    # Parsing lat and lon then store them

    data = readedText.split(',')
    print('Latitude: {0} | Longitude: {1}'.format(data[0], data[1]))
    latitude_list.append(float(data[0]))
    longitude_list.append(float(data[1]))
print("Finished !")
s.close()

webbrowser.open("map.html")