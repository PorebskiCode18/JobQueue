#include <vector>
#include "job.hpp"

class JobQueue{
private:
    std::vector<Job> heap;
    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }
    void siftDown(int i)
    {
        int n = heap.size();
        while (true)
        {
            int largest = i;
            int l = left(i);
            int r = right(i);

            if (l < n && heap[largest] < heap[l]) largest = l;
            if (r < n && heap[largest] < heap[r]) largest = r;

            if (largest == i) break;

            std::swap(heap[i], heap[largest]);
            i = largest;
        }
    }
    void siftUp(int i)
    {
        while (i > 0 && heap[parent(i)] < heap[i])
        {
            std::swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
public:
    void insert(Job job)
    {
        heap.push_back(job);
        siftUp(heap.size() - 1);
    }

    void runHighestPriority()
    {
        if (heap.empty())
        {
            std::cout << "No jobs to run." << std::endl;
            return;
        }
        heap[0].execute();
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) siftDown(0); //pushes new root into place

    }
};
