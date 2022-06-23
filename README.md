# ros_snap
- Require: ROS-Melodic
- Reference link: http://wiki.ros.org/ROS/Tutorials/Packaging%20your%20ROS%20project%20as%20a%20snap

# Build .snap file
- Install snapcraft: $sudo snap install --classic snapcraft
- Direct to folder creating .snap file
- Create snapcraft.yaml file: $snapcraft init
- Edit snapcraft.yaml file
- Build .snap file: $snapcraft
- Install .snap file: $sudo snap install ros-test-snap_1.0.0_amd64.snap --devmode
- Test: $ros-test-snap

# Share .snap file
- Login to Snapsraft: $snapcraft login
- Enter the gmail and pass
- Register snap file: $snapcraft register ros-test-snap_1.0.0_amd64.snap
- Direct to folder containing .snap file
- Push: $snapcraft push ./ros-test-snap_1.0.0_amd64.snap --release=stable

# Install .snap file from Snapcraft
- Install: $sudo snap install ros-test-snap_1.0.0_amd64.snap