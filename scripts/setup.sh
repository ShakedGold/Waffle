#! /bin/bash

GLFWDIR=$(pwd)/../glfw
IMGUIDIR=$(pwd)/../imgui
SCRIPTDIR=$(pwd)

# Compile and Build GLFW
unamestr="$(uname | tr '[:upper:]' '[:lower:]')"
platform=$(echo $unamestr | grep -Eo "linux|windows")

#check dependencies
if command -v cmake >/dev/null 2>&1 ; then
    echo "cmake found"
else
    echo "cmake not found"
fi


#mkdir $GLFWDIR/build

#echo "Entering glfw generation in $GLFWDIR/build"
#cmake -S $GLFWDIR -B $GLFWDIR/build -D BUILD_SHARED_LIBS=ON
#echo "Finished generating glfw"

#echo "Starting compilation of glfw in $GLFWDIR/build"
#cmake --build $GLFWDIR/build
#echo "Finished compiling glfw"

#echo "Starting GLFW lib install"
#sudo cmake --install $GLFWDIR/build
#echo "Finished installing GLFW lib"

echo "Entering $GLFWDIR"
cd $GLFWDIR
cmake -G "Unix Makefiles"
make
echo "Exiting $GLFWDIR"
cd $SCRIPTDIR

# source settings to be able to call them by variable $var1
# ProjectSettings
source <(grep = <(grep -A5 '\[ProjectSettings\]' ../config/project.ini) | sed 's/ *= */=/g' | sed "s/;/#/g") 2> /dev/null

# setup CMakeLists.txt for project
mkdir $name
mv $name ..
touch CMakeLists.txt
echo "CMAKE_MINIMUM_REQUIRED(VERSION 3.7)
" >> CMakeLists.txt
echo "project($name)" >> CMakeLists.txt
cp CMakeLists.txt ../$name/

sed -i "s/\[projectDir\]/$name/g" WaffleCmake.txt
sed -i "s/\[projectSrc\]/$name\/main.cpp/g" WaffleCmake.txt

cp WaffleCmake.txt ../CMakeLists.txt