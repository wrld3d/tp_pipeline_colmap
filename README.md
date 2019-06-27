
This module adds the COLMAP to tp_pipeline. To use this you will need to build and install the COLMAP.

## Building COLMAP

### Dependencies
```
dnf -y update

dnf groupinstall -y "Development Tools"
dnf install -y gcc-c++ \
	meld \
	git \
	svn \
	wget \
	screen \
	ncurses-devel \
	zlib-devel \
	openssl \
	openssl-devel \
	mesa-libGL \
	mesa-libGL-devel \
	texlive-latex \
	texlive-latex-bin \
	freeimage \
	freeimage-devel \
	glm-devel \
	"perl(Data::Dumper)" "perl(Thread::Queue)" \
	mesa-libGLES-devel mesa-libEGL-devel \
	suitesparse-devel \
	glog-devel \
	gflags-devel \
	CGAL-devel \
	openblas-devel \
	boost-* \
	glew-devel \
	eigen3-devel

```

### CUDA
* [Install CUDA](https://github.com/tdp-libs/general_machine_installation/blob/master/Fedora/NVIDIA.md)

### Build
Following instructions on https://colmap.github.io/install.html

```
#!/bin/bash

set -eu

mkdir colmap
cd colmap/

mkdir usr

git clone https://ceres-solver.googlesource.com/ceres-solver
cd ceres-solver
git checkout $(git describe --tags) # Checkout the latest release
mkdir build
cd build/
cmake .. \
      -DBUILD_TESTING=OFF \
      -DBUILD_EXAMPLES=OFF \
      -DCMAKE_BUILD_TYPE=RELEASE \
      -DCMAKE_INSTALL_PREFIX:PATH=`realpath ../../usr/ceres`
make -j`nproc`
make -j`nproc` install
cd ../..

git clone https://github.com/colmap/colmap
cd colmap
git checkout dev
mkdir build
cd build/
cmake .. \
      -DCMAKE_INSTALL_PREFIX:PATH=`realpath ../../usr` \
      -DCERES_INCLUDE_DIRS=`realpath ../../usr/ceres/include/` \
      -DCERES_LIBRARIES=`realpath ../../usr/ceres/lib64/libceres.a`
make -j`nproc`
make -j`nproc` install

cd ../../..

```

### Add an icon to the menu.
```
cp tp_pipeline_colmap/images/icon.png /opt/tom/colmap/
mkdir ~/.local/share/applications/
nano ~/.local/share/applications/COLMAP.desktop
```

```
[Desktop Entry]
Version=1.0
Type=Application
Name=COLMAP
Exec=/opt/tom/colmap/usr/bin/colmap gui
Icon=/opt/tom/colmap/icon.png
Categories=SfM
```

### Add an SfM folder
```
mkdir ~/.config/menus
cp /etc/xdg/menus/xfce-applications.menu ~/.config/menus/
nano ~/.config/menus/xfce-applications.menu
```

Add this
```
    <Menu>
	<Name>SfM</Name>
        <Directory>sfm.directory</Directory>
        <Include>
            <Or>
                <Category>SfM</Category>
            </Or>
        </Include>
    </Menu>
```
