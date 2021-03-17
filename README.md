# Arduino_Shutter_Tester
This is a Focal Plane Shutter Tester based on the idea I found from the CAMERADACTYL Cameras YouTube channel.
I took the idea and expanded it to use two laser sensors and laser emitters. This isn't the most ideal setup as getting everything lined up and keeping it lined up is difficult at times.
In the future I plan to try using PhotoTransistors to see if that creates at least an easier setup.
Currently the sensors are placed in a way so that they sit at the diagonal corners of the 35mm Film plane. This allows for testing both Horizontal and Vertical shutters.
This tester calculates Shutter Speeds on both edges of the Shutter Plane in order to help check and adjust exposure/shutter deviation.
It also calculates Curtain speeds across the focal plane. Without knowing the exact distances from sensor to sensor this is mostly for reference.
Future variations could have the sensors set at measured specific points allowing for curtain measurements that could then be compared to Service Manuals.
The biggest downfall is that I have it set to only printout data after Sensor 2 gets its data set. If this doesn't occur then nothing will print out.
