#include <stdio.h>

int main()
{
	int e[100][100];
	int k,i,j,n,m;
	int d1,d2,weight,m1,m2;
	int inf = 999;//表示路不通
	//n表示顶点个数  m表示边的个数
	printf("地点用数字表示~\n");
	printf("请输入地点的个数+路的个数：\n");
	scanf("%d%d",&n,&m);
	//初始化
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j)
				e[i][j] = 0;
			else
				e[i][j] = inf;

	//读入边
	printf("输入地点+地点+时间：\n");
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&d1,&d2,&weight);
		e[d1][d2] = weight;
	}

	//Floyd算法核心语句
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(e[i][k]+e[k][j]<e[i][j])
					e[i][j] = e[i][k] + e[k][j];

	//输出最终结果
	printf("\n下表为各两点间地点间所花费时间：\n");
	printf("ps: 999表示两地点不通~\n");
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=n;j++)
			printf("%10d",e[i][j]);
        printf("\n");
	}
	printf("\n");

    printf("请输入你想去得的两个地方：\n");
    while(scanf("%d%d",&m1,&m2)==2)
    {
        printf("两地间花的最少时间为：%d",e[m1][m2]);
        printf("\n");
    }

	return 0;

}
