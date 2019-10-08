#include <stdio.h>
#define MAXV 1010
#define INF 0xffffff					//�����
int n,m;
int Dist[MAXV][MAXV],Cost[MAXV][MAXV];
int s,t;
void Dijkstra(int s)					//�ҿ�˹�����㷨
{	int dist[MAXV];
    	int cost[MAXV];
    	int S[MAXV];
    	int mindist,mincost,u;
    	int i,j;
    	for(i=1;i<=n;i++)				//dist��cost��S��ʼ��
    	{	dist[i]=Dist[s][i];
        	cost[i]=Cost[s][i];
        	S[i]=0;
    	}
    	dist[s]=cost[s]=0;
    	S[s]=1;
    	for(i=0;i<m;i++)
    	{	mindist=INF;
      	for(j=1;j<=n;j++)			//��V-S�е���С����mindist
        		if (S[j]==0 && mindist>dist[j])
            		mindist=dist[j];
        	if (mindist==INF) break;		//�Ҳ�����ͨ�Ķ���
      	mincost=INF; u=-1;
      	for(j=1;j<=n;j++)			//����δ���ǵġ�������С�Ķ���u
        	{	if (S[j]==0 && mindist==dist[j] && mincost>cost[j])
            	{	mincost=cost[j];		//��distΪ��С�Ķ���������Сcost�Ķ���u
                	u=j;
            	}
        	}
        	S[u]=1;					//������u����S����
        	for (j=1;j<=n;j++)			//���Ƕ���u,��s��ÿ������j�����·�����Ⱥͻ���
        	{	int d=mindist+Dist[u][j];	//d��¼��������u��·������
            	int c=cost[u]+Cost[u][j];	//c��¼��������u�Ļ���
            	if(S[j]==0 && d<dist[j])
            	{	dist[j]=d;
                	cost[j]=c;
            	}
            	else if(S[j]==0 && d==dist[j] && c<cost[j])
                	cost[j]=c;			//�ж���������ͬ�����·��
        	}
        	if(S[t]==1)					//�Ѿ����s��t�����·��
        	{	printf("%d %d\n",dist[t],cost[t]);
            	return;
        	}
    	} 
}
int main()
{	int a,b,d,p;
    	int i,j;
   	while(scanf("%d%d",&n,&m)!=EOF)
    	{	if(m==0 && n==0)
            	break;
        	for(i=1;i<=n;i++)
        	{	for(j=1;j<=n;j++)
            	{	Dist[i][j]=INF;
                	Cost[i][j]=INF;
            	}
        	}
        	for(i=0;i<m;i++)
        	{	scanf("%d%d%d%d\n",&a,&b,&d,&p);
            	if(Dist[a][b] > d)
            	{	Dist[a][b]=Dist[b][a]=d;	//����ͼ�ı��ǶԳƵ�
                	Cost[a][b]=Cost[b][a]=p;
            	}
        	}
        	scanf("%d%d",&s,&t);
        	Dijkstra(s);
    	}
    	return 0;
}
