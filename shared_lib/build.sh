g++ -shared -fPIC ./lib.cpp -o libtest.so
g++ ./main.cpp -ldl -o loader
