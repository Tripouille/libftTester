# libftTester (2019+)
Tester for the libft project of 42 school (with personalized leaks checking on mac, using valgrind on linux)  
*If all your tests are OK and the moulinette KO you, please send an email with make sendfunction ex: make sendsubstr or contact me on slack/discord for improvements*  
Clone this tester in your libft repository, or somewhere else and customize the path to your libft project by changing the LIBFT_PATH variable inside the Makefile. Relative paths (`../`) may not work correctly depending on the OS, so if you face any issues, try using an absolute path instead (`/Users/****/`).

![alt text](https://i.imgur.com/EWmbpxx.png)  


# Commands
make m = launch mandatory tests  
make b = launch bonus tests  
make a = launch mandatory tests + bonus tests  
make [funtion name] = launch associated test ex: make calloc  
 
make dockerm = launch mandatory tests in linux container  
make dockerb = launch bonus tests in linux container  
make dockera = launch mandatory tests + bonus tests in linux container  
make docker[funtion name] = launch associated test in linux container ex: make dockercalloc  
Thanks to gurival- for the docker idea (https://github.com/grouville/valgrind_42)  

make vs[funtion name] = open the corresponding tests in vscode ex: make vscalloc  


# Setup docker in goinfre for 42 mac  
rm -rf ~/Library/Containers/com.docker.docker  
rm -rf ~/.docker  
rm -rf /goinfre/${USER}/docker /goinfre/${USER}/agent  
mkdir -p /goinfre/${USER}/docker /goinfre/${USER}/agent  
ln -s /goinfre/${USER}/agent ~/Library/Containers/com.docker.docker  
ln -s /goinfre/${USER}/docker ~/.docker  


# Outputs
![alt text](https://i.imgur.com/en8rJpS.png)  
![alt text](https://i.imgur.com/ZvzhIoZ.png)  
![alt text](https://i.imgur.com/KrlN2Pg.png)  

MOK / MKO = test about your malloc size (this shouldn't be tested by moulinette)  


# Report bugs / Improvement
Contact me on slack or discord : jgambard or use make sendfunction ex make sendsubstr if all your tests were OK and the moulinette KO you.  
