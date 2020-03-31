In mechanical engineering, robotics and animations, kinematics is used to describe the motion of systems composed of joined parts such as an engine, a robotic arm or the human skeleton. **Robot Kinematics** is a light-weight **C** API specifically designed for robotics. They compute transformations of kinematic chain with rotary joints. The main applications are for robot arms, quadruped robots and humanoid robots.

![Robot arm kinematics](../robot-arm-kinematic1.png)

With the application of some linear algebra, forward kinematics is done by iterative multiplication of transform matrices each computed from **DH** (**Denavit Hartenberg**) parameters for each link transform. The library also handles the resultant matrix for extraction of translation vector and rotation in **Euler Angles** (roll, pitch and yaw). Using forward kinematics, the output of a mechanism obtained from joint variables can be computed and visualized (both translation and rotation).

For inverse kinematics which is needed for obtaining joint variables for a specific coordinate of an end-effector. **FABRIK** (Forward And Backward Reaching Inverse Kinematics) which is very popular in the era of ragged doll animations is used with some modifications to fit our application.

### Globals

You can see a list of data structures, functions and macros [**here**](globals.html).