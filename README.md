# ros_snap
- Require: ROS-Melodic
- Reference link: http://wiki.ros.org/ROS/Tutorials/Packaging%20your%20ROS%20project%20as%20a%20snap

# Build .snap file
- Install snapcraft: $sudo snap install --classic snapcraft
- Direct to folder creating .snap file
- Create snapcraft.yaml file: $snapcraft init
- Edit snapcraft.yaml file
- Build .snap file: $snapcraft
- Install .snap file: $sudo snap install <snap_file>.snap --devmode
- Test: $ros-test-snap

# Share .snap file
- Login to Snapsraft: $snapcraft login
- Enter the gmail and pass
- Register snap file: $snapcraft register <snap_file>.snap
- Direct to folder containing .snap file
- Push: $snapcraft push ./<snap_file>.snap --release=stable

# Install .snap file from Snapcraft
- Install: $sudo snap install <snap_file>.snap

# Remove snap
- Check snap list: $snap list
- Remove snap: $sudo snap remove <snap_name>