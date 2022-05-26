#include "VectorEqual.h"

bool VectorEqual(std::vector<int> vector)
{
        int start = vector[0];
        for (int i = 1; i < vector.size(); i++)
        {
            if (vector[i] == start && start > 0)
                continue;
            else
            {
                return false;
            }
        }
        return true;

}
