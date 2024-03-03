**About**

This is a simple in memory key value storage system similar to redis/memcached

**Brief**

This program basically takes input from user and manages key values pair as per the input command/op

**Project structure**
1. The file structure is simple and modular
2. All the translation unit/ source file are in */src* directory of the root folder 
   and all the custom header files are in */src/includes* folder
3. There is also a */demo* folder that has a demo simple implementation of the project
4. When compiling you can store the binaries in */bin* folder which is in the root directory

**Build Me**
1. create a bin in the root of the folder 
2. go to the src folder and run gcc [files that need to be compiled/*.c] -g -o ../bin/{name of the executable}
     a. Ideally this should be in a make file

**Code design**
1. This is a very simple design structure to follow
     a. All constants like buffer size limit etc are declared using macros (#define) in the header file 
     b. All source files have their own header file which has exported functions (function declaration) and the #define constants
     
     input >> | main.c | -> |controller.c| -> | handler.c | -> [ | *_api.c | ]  
                               |
                             output <<
2. 
     a. *main.c* is the entry point of the program that receives the input
     b. *controller.c* processes and breaks down the input into  command and arguments also it validates the command and its arguments
     c. *handler.c* This is the bridge between user commands and the op/api that needs to be executed/used.
     d. **_api.c* These are basically the api source files for a particular type of storage for example 
          simple key value pair, sorted sets, hashed sets etc. (currently only key value sets are being used)
      
**To dos** 
1.  Add a make file to build the project
2.  Add few more api functionalities for SET
3.  Support network connection and concurrent request handling
4.  Add multiple API's 
     -> lists
     -> hashed sets
     -> sorted lists

