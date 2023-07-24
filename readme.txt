编译/运行单个cpp文件：
	Code Runner插件,右键 -> Run Code 或者点击编辑区右上角三角形

	设置： settings -> extensions -> code-runner.executorMap

编译运行多个cpp文件:
	方式1：c/c++插件, 按f5; 需要配置tasks.jshon和 launch.json
	方式2: cmake tools插件，点击右下角 build ->run

声明和定义区别：
	声明：只表明变量的数据类型和属性，不分配内存
	定义：分配内存

vscode智能提示使用c++11: 
		c_cpp_properties.json :
			"cStandard": "c11",
            "cppStandard": "gnu++11"

 eclipse 下会提示std::to_string()找不到
 解决方法：
 	参考：https://www.tuicool.com/articles/z6zUzy7
		https://stackoverflow.com/questions/14381137/eclipse-function-to-string-could-not-be-resolved
 	a.本Project->Properties->C/C++Build->Settings->GCC C++ Compiler->Miscellaneous->添加-std=c++11
 		添加之后是  -c -fmessage-length=0 -std=c++11
  		c++14就添加 -std=c++14
  	b.本Project->Properties->C/C++General->Paths And Symbols ->Symbols->GNC c++ 添加__cplusplus  201103L
  		  c++14 就添加__cplusplus  201402L
  	c.Window -> Preferences -> C/C++ -> Build -> Settings -> Discovery tab->choose CDT GCC Built-in Compiler Settings
 		  添加 -std=c++11.添加之后是这样：  ${COMMAND} ${FLAGS} -E -P -v -dD -std=c++11 "${INPUTS}"
    c.重启
    d.【右键本Project】->Index->Rebuild
	2019的eclipse有bug，build完之后，刷新一下目录里的binary才显示出来，然后才可以run


.vscode:
	https://code.visualstudio.com/docs/cpp/config-linux
	https://zhuanlan.zhihu.com/p/92175757
	tasks.json:
		编译代码配置，包括编译工具gcc/g++，生成elf文件路径
	launch.json:
		debug和运行设置
