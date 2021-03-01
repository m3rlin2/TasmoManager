export PATH=$QTDIR/bin:$PATH

export BUILD_PATH=$APPVEYOR_BUILD_FOLDER/build
export CMAKE_PREFIX_PATH=$HOME/Qt/5.12.10/clang_64

APP_VERSION=$(git describe --tags --always HEAD)
export APP_VERSION
export APP=tasmomanager-$APP_VERSION