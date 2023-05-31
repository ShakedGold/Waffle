#! /bin/bash

SCRIPTDIR=$(pwd)
WAFFLEDIR=$(echo $(pwd)/../ | sed -E "s/(scripts\/\.\.\/)//g" | sed "s/\/$//g")
GLFWDIR=$WAFFLEDIR/glfw
IMGUIDIR=$WAFFLEDIR/imgui

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
source <(grep = <(grep -A5 '\[ProjectSettings\]' $WAFFLEDIR/config/project.ini) | sed 's/ *= */=/g' | sed "s/;/#/g") 2> /dev/null

PROJECTDIR=$WAFFLEDIR/$name

# setup CMakeLists.txt for project
mkdir $name
mv $name $WAFFLEDIR/

sed -i "s/\[projectDir\]/$name/g" WaffleMainCmake.txt
sed -i "s/\[projectDir\]/$name/g" ProjectCmake.txt

cp WaffleMainCmake.txt $WAFFLEDIR/CMakeLists.txt
cp ProjectCmake.txt $PROJECTDIR/CMakeLists.txt
cp main.cpp $PROJECTDIR/main.cpp

echo "Succefully Created Project"
echo "Project $name is located at $PROJECTDIR"
