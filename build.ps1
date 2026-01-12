Remove-Item -r build
New-Item -ItemType Directory build
cd build
cmake .. -G "Ninja"
ninja