/*�ļ�����E008.h
���ߣ�YZY
˵����
�ϴ��޸�ʱ�䣺2019/11/22
*/
#pragma once
namespace E008 {
	//#include <iostream>
//#include <boost/lexical_cast.hpp> 
//#include <boost/lexical_cast.hpp>   
		using namespace std;

	class Solution {
	public:
		
			
		
	};
	void Test() {
		typedef adjacency_list<vecS, vecS, bidirectionalS> Graph;
		// Make convenient labels for the vertices
		enum { A, B, C, D, E, N }; //���� 0 ��1��2��3��4 ����,����NΪ������
		const int num_vertices = N;//N��ֵ��5
		const char* name = "ABCDE";
		//ͼ�еı�
		typedef std::pair<int, int> Edge;
		Edge edge_array[] = { Edge(A,B), Edge(A,D), Edge(C,A), Edge(D,C),
								Edge(C,E), Edge(B,D), Edge(D,E) };
		const int num_edges = sizeof(edge_array) / sizeof(edge_array[0]);
		// ����һ��ӵ��5�������ͼ����
		Graph g(num_vertices);
		// ��ͼ������ӱ�
		for (int i = 0; i < num_edges; ++i)
			add_edge(edge_array[i].first, edge_array[i].second, g);

    }
	
}
