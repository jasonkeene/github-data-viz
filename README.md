
## Getting Started

# Mac OSX

Make sure to have Xcode and openFrameowrks installed. You can download
openFrameworks [here](http://www.openframeworks.cc/versions/v0.8.4/of_v0.8.4_osx_release.zip)
and then follow the instructions [here](http://openframeworks.cc/setup/xcode/).

Clone down the repo into your apps directory:

    cd $OF_ROOT/apps/myApps
    git clone git@github.com:jasonkeene/github-data-viz.git
    cd github-data-viz

From here you can launch the xcode project:

    open githubDataViz.xcodeproj

You can also issue this command to build and launch the app:

    xcodebuild && open bin/githubDataViz.app

# Windows

Make sure to have Code::Blocks and openFrameowrks installed. You can download
openFrameworks [here](http://www.openframeworks.cc/versions/v0.8.4/of_v0.8.4_win_cb_release.zip)
and then follow the instructions [here](http://openframeworks.cc/setup/codeblocks/).

Clone down the repo into your apps directory. From here you can launch the
Code::Blocks workspace. You may need to enable C++11 under your build options.

# Linux

Follow the guide on [openframework's site](http://openframeworks.cc/setup/linux-codeblocks/)
