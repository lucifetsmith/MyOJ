struct ListNode {
	ListNode(int);
	int key;
	ListNode* next;
};

ListNode::ListNode(int val) : key(val), next(nullptr)
{}

#define LIST_INSERT(list, node, cur, pre) \
	do { \
		cur = list; \
		pre = nullptr; \
		if (!list) { \
			list = node; \
			break; \
		} \
		while (cur) { \
			if (cur->key > node->key) break; \
			pre = cur; \
			cur = cur->next; \
		} \
		if (!pre) { \
			node->next = list; \
			list = node; \
			break; \
		} \
		if (!cur) { \
			pre->next = node; \
			break; \
		} \
		pre->next = node; \
		node->next = cur; \
	} while (0)
#define BUCKET_NUM_MAX	4

void BucketSort(int* arr, int num)
{
	int max = 0x80000001, min = 0x7fffffff;
	ListNode* bucket[BUCKET_NUM_MAX] = {0};
	int bucketNum;
	int i;
	for (i = 0; i < num; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	int gop = (max + BUCKET_NUM_MAX - min) / BUCKET_NUM_MAX;
	if (gop == 1) {
		bucketNum = max - min;
	}
	else {
		bucketNum = BUCKET_NUM_MAX;
	}
	int location;
	ListNode *node = nullptr, *cur = nullptr, *pre = nullptr;
	for (i = 0; i < num; i++) {
		location = (arr[i] - min) / gop;
		node = new ListNode(arr[i]);
		LIST_INSERT(bucket[location], node, cur, pre);
	}
	int j;
	for (i = 0, j = 0, cur = nullptr; i < bucketNum; i++) {
		cur = bucket[i];
		while (cur) {
			arr[j++] = cur->key;
			pre = cur;
			cur = cur->next;
			delete pre;
		}
	}
}