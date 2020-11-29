# libftTester


Clone this tester in your libft repository. (works on linux and mac)  
![alt text](https://i.imgur.com/EWmbpxx.png)


# Commands
make m = launch mandatory tests  
make b = launch bonus tests  
make a = launch mandatory tests + bonus tests 

make vm = launch mandatory tests with valgrind  
make vb = launch bonus tests with valgrind   
make va = launch mandatory tests + bonus tests with valgrind  

make [funtion name] = lauch associated test ex: make calloc  
make v[funtion name] = lauch associated test with valgrind ex: make vcalloc  
make vs[funtion name] = lauch associated test with valgrind then open the corresponding tests in vscode ex: make vscalloc  


# Outputs

![alt text](https://i.imgur.com/Mx1jePL.png)
![alt text](https://i.imgur.com/HkCGPjC.png)

MOK / MKO = test about your malloc size (this shouldn't be tested by moulinette)  
lstclear and lstdelone are force tested with valgrind (CHECK WITH VALGRIND) even if you run make b (for safety) if you want force without valgrind you should use make lstclear and make lstdelone  

# Report bugs / Improvement
Contact me on slack or discord : jgambard
