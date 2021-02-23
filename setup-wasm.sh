#!/bin/bash

pushd

function goBackDir {
	popd
}

trap goBackDir EXIT

set -eux
cp index.html build/index.html
cp pre.js  build/pre.js

mkdir -p build
cd build
emcmake cmake ..
emcmake make
# em++ -g0 libfilesystem.a -o filesystem.js --bind -lidbfs.js -s ALLOW_MEMORY_GROWTH=1 -s MAXIMUM_MEMORY=4GB --pre-js pre.js
em++ -g0 libfilesystem.a -o filesystem.js --bind -lnodefs.js -s ALLOW_MEMORY_GROWTH=1 -s MAXIMUM_MEMORY=4GB --pre-js pre.js