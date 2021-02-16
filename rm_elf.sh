#！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
#！！！！！！！！删除当前及子目录下所有 ELF格式文件; 谨慎使用！！！！！！！！
#！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！


RED='\033[31m'
GREEN='\033[32;1m' #1是加粗字体
YELLOW='\033[33m' 
BLUE='\033[34m' 
END='\033[0m'


file_count=0
file_list=()
#定义一个函数;递归找到该目录下所有elf文件
function traverse(){
	#注意符号是 esc按键的符号
	for file in `ls $1` #将命令的结果作为变量
	do 
		if [ -d $1"/"$file ] #如果是文件夹的话则继续递归遍历; if后面方括号两边都要有空格
		then 	
			traverse $1"/"$file
			# echo $1"/"$file
		else
			path=$1"/"$file

			#如果不是.cpp文件，不是.c文件，不是.h文件........
			#等号两边注意有空格;注释和"]"要有空格
			if [ "${path##*.}" != "cpp" ]&&[ "${path##*.}" != "c" ]\
				&&[ "${path##*.}" != "h" ]&&[ "${path##*.}" != "txt" ]\
				&&[ "${path##*.}" != "make" ]&&[ "${path##*.}" != "cmake" ]\
				&&[ "${path##*.}" != "o" ]&&[ "${path##*.}" != "sh" ]\
				&&[ "${path##*.}" != "bin" ]  #.bin文件也不删除; cmake会产生.bin文件
			then
				fileName=`basename $file` #basename是提取文件名的关键字;这里fileName这个变量下文没用到

				fileInfo=$(file $path) #这里file是个命令;获取文件信息如： allToUtf8.sh: UTF-8 Unicode text
				encodeInfo=${fileInfo##*:} #截取最右边"："的字符串，如：UTF-8 Unicode text
				
				encode=$encodeInfo #将一个变量赋给一个新变量	

				# echo $fileName

				if [[ $encodeInfo == *,* ]];then #encodeInfo包含","
					encode=${encodeInfo%%,*} #从左边起截取第一个","左边的字符串
				fi

				if [[ $encodeInfo = *ELF* ]];then
					# echo -e ${RED}"delete "$path"-->"$encode ${END}
					# rm $path
					file_count=`expr $file_count + 1` # 符号"+"两边要有空格
					file_list[$file_count]=$path
					
				fi 
				
			fi
		fi
	
	done
}

function print_elf_file(){
	#将所有elf文件都打印出来
	for file in ${file_list[@]} # *和@都行
	do 
		# echo -e ${BLUE}$file ${END}
		echo $file
	done
}

function is_delete(){
	#需要手动确认
	echo -n -e ${RED}"确定要删除这些文件吗y/n?${END}"
	read cmd
	
	cmd_len=`expr length "$cmd"` #长度为0则认为是回车键
	# echo "cmd 长度:"$len
	if [ $cmd_len = 0 ]||[ $cmd = "y" ]; then
		for file in ${file_list[@]} # *和@都行
		do 
			echo -e ${RED}"delete "$file ${END}
			rm $file
		done
		echo -e ${GREEN}"已经删除所有elf文件！！！" ${END}
	else	
		echo -e ${RED}"不删除文件" ${END}
	fi
}


folder="."
traverse $folder

if [ $file_count = 0 ]; then
	echo -e ${RED}"无elf文件 "${END}
else
	print_elf_file #调用函数,打印所有elf文件
	is_delete #调用函数，是否删除
fi

