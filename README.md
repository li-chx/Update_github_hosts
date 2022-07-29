# Update_github_hosts
## 一、介绍
**该软件仅用于windows**  
这是一个基于https://github.com/521xueweihan/GitHub520 的github hosts自动化更新程序。（指自动获取hosts内容并写入系统hosts文件）
## 二、使用方法
### 手动使用
1. 首先应备份你的hosts文件，hosts文件位于C:\Windows\System32\drivers\etc  
	1.  找到该文件，原地复制粘贴
	2.  将副本命名为**hosts.bak**  
	#### 这很重要，因为程序将读取hosts.bak
2.  下载release中的Update_github_hosts.exe。  
3.  以管理员身份运行该软件。
### 自动启动
1.  自动启动的版本和手动启动的版本相当类似，但是删除了所有的getchar()并静默运行。  
2.  下载release中的Update_github_hosts(start).exe，在注册表中写入相关的自启动配置即可。  
## 三、软件流程
1.  删除hosts
2.  复制hosts.bak的内容到hosts
3.  获取github hosts文件，并追加在本机hosts文件中
4.  ipconfig /flushdns
## 四、作者的话
首先，这个软件基于libcurl和521xueweihan的项目，**快去给他们star**
>https://github.com/521xueweihan/GitHub520
  
这是我的第一个上传到Github的项目，也是我自学过程中最正式的一个项目，整个流程下来真的学到了很多。  
首先是libcurl这种第三方库的使用，因为我第一次用，从编译到使用真是困难重重。  
然后是vs中一个解决方案下两个工程，怎么切换你F5时调试的工程，怎么调用其他工程的文件（最后没弄，累了），这些都是不实际去做不会想到的问题。  
最后，作为一个要公开的GitHub项目，学习了如何写markdown（~~写的稀烂~~），如何让大家能看懂我写的工程（~~我自己都不用~~）。  
欢迎大家Pull requests，正好我可以学习怎么处理。~~说实话我不相信谁会给这玩意Pull requests~~
### 还有一件事，我觉得改DNS比改hosts效果好。
