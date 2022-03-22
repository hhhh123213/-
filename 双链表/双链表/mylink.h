
#ifndef DLL_IMPORT
#define API __declspec(dllexport)
#else 
#define API __declspec(dllimport)
#endif // !DLL_IMPORT
#define HEAD extern "C"
typedef struct Node
{
	int num;
	Node* next;
	Node* last;
};

HEAD class API SLinkList
{
private:
	Node* head;
	int length;
public:
	SLinkList();
	SLinkList(int* list, int n);
	void HeadInsertNode(int num);
	void InsertNode(int n, int num);
	void EndInsertNode(int num);
	void DeleteNode(int n);
	void Delete();
	bool Empty();
	int Length();
	void disLinkList();
	Node*GetNode(int n);
	bool GetElem(int n, int& num);
	int LocateElem(int num);
};