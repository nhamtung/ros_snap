# ros_snap
- Require: ROS-Melodic
- Reference link: 
    + http://wiki.ros.org/ROS/Tutorials/Packaging%20your%20ROS%20project%20as%20a%20snap
    + https://snapcraft.io/docs/getting-started

# Build .snap file
- Install snapcraft: $sudo snap install --classic snapcraft
- Create folder: $mkdir ~/<folder_name>
- Direct to folder .snap file: $cd ~/<folder_name>
- Create snapcraft.yaml file: $snapcraft init
- Edit snapcraft.yaml file:
```
name: ros-test-snap # you probably want to 'snapcraft register <name>'
base: core18 # the base snap is the execution environment for this snap
version: '1.0.0' # just for humans, typically '1.2+git' or '1.3.2'
summary: Test snap with talker_listener package # 79 char long summary
description: |
  Description for ros-test-snap
# grade: devel # must be 'stable' to release into candidate/stable channels
confinement: devmode # use 'strict' once you have the right plugs and slots
parts:
  talker-listener:
    plugin: catkin
    source: https://github.com/nhamtung/ros_snap.git
    source-branch: main
    source-space: talker_listener/
    # catkin-packages: [talker_listener]              # (list of strings) List of catkin packages to build. If not specified, all packages in the workspace will be built. If set to an empty list ([]), no packages will be built.
    # source-space: src                               # (string) The source space containing Catkin packages. By default this is src.
    # include-roscore: true                           # (boolean) Whether or not to include roscore with the part. Defaults to true.
    # rosinstall-files:                               # (list of strings) List of rosinstall files to merge while pulling. Paths are relative to the source.
    # recursive-rosinstall: false                     # (boolean) Whether or not to recursively merge/update rosinstall files from fetched sources. Will continue until all rosinstall files have been merged. Defaults to false.
    # catkin-cmake-args:                              # (list of strings) Configure flags to pass onto the cmake invocation from catkin.
    # catkin-ros-master-uri: http://localhost:11311   # (string) The URI to ros master setting the env variable ROS_MASTER_URI. Defaults to http://localhost:11311.
apps:
  ros-test-snap:
    command: roslaunch talker_listener topic.launch
```
- Build .snap file: $snapcraft
- Install .snap file: $sudo snap install <snap_file>.snap --devmode
- Test: $ros-test-snap

# Share .snap file
- Login to Snapsraft: $snapcraft login
- Enter the gmail and pass
- Register snap file: $snapcraft register <snap_name>.snap
- Direct to folder containing .snap file
- Push: $snapcraft push ./<snap_file>.snap --release=stable

# Install .snap file from Snapcraft
- Install directly: 
    + Direct to .snap folfer
    + Install: $sudo snap install <snap_file>.snap
- Install from snap store: 
    + Find package: $sudo snap find <snap_name>
    + Install: $sudo snap install <snap_name>

# Update snap
- Check snap list: $snap list
- Update snap: $sudo snap refresh <snap_name>

# Remove snap
- Check snap list: $snap list
- Remove snap: $sudo snap remove <snap_name>

# Revert to a previously used snap
- Check snap list: $snap list
- Revert snap: $sudo snap revert <snap_name>

# Disable/Enable snap
- Check list: $snap list
- Disable: $sudo snap disable <snap_name>
- Enable: $sudo snap enable <snap_name>

# Create and restore a snapshot 
- Desception: Snapshot can be used to backup the state of your snaps, revert snaps to a previous state and to restore a fresh snapd installation to a previously saved state
- Create snapshot: $sudo snap save <snap_name>
- Restore: $sudo snap restore <set_name>