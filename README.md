# objectpose_transform
Markup :  ## Heading 2 ##
ROS transforms for TOASTER package. 

There are three different object in Morse Simulator Environment and objective is to make these objects such that TOASTER can use. 
For this purpose, this package is created. It simply converts coming pose data from these three objects to ros tf type. 
In order to use this package you should have installed TOASTER, Morse simulator and created three different objects in Morse 
environment. You can change object names simply changing corresponding c++ ROS node in this repository.

Markup :  # Heading 3 #
General Procedure to make TOASTER to read object data from MORSE simulator:
After adding an object to morse environment, one should edit
MorseObjectReader.cpp in order to read this objects from toaster. For this purpose, a pose
sensor is added to all fork, plate and bluecup objects and these sensors are attached to ros
interface. Then a ros package is created named as “objectpose_transform”. Under this package,
we have three c++ ros node, their names are objectpose_transform(for bluecup), forktransform
and platetransform. In these nodes, the data coming from pose sensor( type is PoseStamped)
are converted to ros tf data type.
