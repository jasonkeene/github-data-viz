
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

In order to properly run this program, you will need to download Code::Blocks, openFrameworks 
and the codeblocks library addittions. You can download openFrameworks [here] 
(http://www.openframeworks.cc/versions/v0.8.4/of_v0.8.4_win_cb_release.zip) and then follow the 
instructions [here](http://openframeworks.cc/setup/codeblocks/).

Once you have completed these steps, clone down the repo into your MyApps directory that is 
located inside your openFrameworks folder (e.g. Local Disk(C:) > Program Files > openFrameworks > apps > myApps). From here you can launch the Code::Blocks workspace File and build the project (it may take a while). You might need to enable C++11 under your build options.


# Linux

Follow the guide on [openframework's site](http://openframeworks.cc/setup/linux-codeblocks/)
