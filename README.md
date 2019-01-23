# Data-Structure-test
2017下半年-大二上学期-数据结构上机实验

### 2017.11.1 --- 顺序表和链表的实现和应用

```
定义一个包含学生信息（学号，姓名，成绩）的的顺序表和链表，使其具有如下功能：   
(1) 根据指定学生个数，逐个输入学生信息；
(2) 逐个显示学生表中所有学生的相关信息；   
(3) 根据姓名进行查找，返回此学生的学号和成绩；   
(4) 根据指定的位置可返回相应的学生信息（学号，姓名，成绩）；   
(5) 给定一个学生信息，插入到表中指定的位置；   
(6) 删除指定位置的学生记录；   
(7) 统计表中学生个数。   
```

### 2017.11.3 --- 栈和队列的实现和应用


#### 进制转换 
```
用顺序栈或链栈实现将一个十进制数N转换为r（r=2,8,16）进制数。
实验步骤：
（1）定义顺序栈或链栈的存储结构；
（2）实现顺序栈或链栈的初始化、判断是否为空、进栈、出栈等基本操作
（3）调用顺序栈或链栈的基本操作实现进制转换
```

#### 舞伴问题

```
  假设在周末舞会上，男士们和女士们进入舞厅时，各自排成一队。跳舞开始时，依次从男队和女队的队头
上各出一人配成舞伴。若两队初始人数不相同，则较长的那一队中未配对者等待下一轮舞曲，算法输出此队列
中等待者的人数及排在队头的等待者的名字，他（或她）将是下一轮舞曲开始时第一个可获得舞伴的人。
要求用循环队列或链队列模拟上述舞伴配对问题。
实验步骤：
（1）定义循环队列或链队列的存储结构；
（2）实现循环队列或链队列的初始化、判断是否为空、入队、出队、取对头元素等基本操作；
（3）调用循环队列或链队列的基本操作实现舞伴配对问题

```

### 2017.11.19 --- 二叉树的遍历和线索、哈夫曼编码算法的实现

```
用递归的方法实现以下算法：
1．以二叉链表表示二叉树，建立一棵二叉树
2．输出二叉树的中序遍历结果
3．输出二叉树的前序遍历结果
4．输出二叉树的后序遍历结果
5．计算二叉树的深度
6．统计二叉树的结点个数 
7．统计二叉树的叶结点个数
8．统计二叉树的度为1的结点个数
9．输出二叉树中从每个叶子结点到根结点的路径。

10. 实现一个哈夫曼编码系统，系统包括以下功能：
(1) 字符信息统计：读取待编码的源文件SourceFile.txt，统计出现的字符及其频率。
(2) 建立哈夫曼树：根据统计结果建立哈夫曼树。
(3) 建立哈夫曼码表：利用得到的哈夫曼树，将各字符对应的编码表保存在文件Code.txt中。
(4) 对源文件进行编码：根据哈夫曼码表，将SourceFile.txt中的字符转换成相应的编码文件ResultFile.txt。
```

### 2017.11.30 --- 图的基本操作和应用

```
  假设以一个带权有向图表示某一区域的公交线路网，图中顶点代表一些区域中的重要场所，
弧代表已有的公交线路，弧上的权表示该线路上的票价（或搭乘所需时间），试设计一个交通
指南系统，指导前来咨询者以最低的票价或最少的时间从区域中的某一场所到达另一场所。
(1) 定义结点结构，定义图结构。
(2) 存储图信息；
(3) 定义求任意两点最短路径函数；
(4) 写出主函数。
```

### 2017.12.20 --- 排序综合
```中文
插入排序
选择排序
冒泡排序
堆排序
归并排序
基数排序
```

### Others

```
栈
链表
链队
顺序表
循环队
哈希表
平衡二叉树
二叉排序树
顺序查找和二分查找
```
