#include <iostream>
#include "Serializer.hpp"

int main() {
    Data original;
    original.id = 42;
    original.name = "yussaito";

    uintptr_t raw = Serializer::serialize(&original);

    Data* result = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << &original << std::endl;
    std::cout << "Deserialized pointer: " << result << std::endl;

    std::cout << "ID: " << result->id << ", Name: " << result->name << std::endl;

    if (result == &original)
        std::cout << "✅ Success: Pointers match" << std::endl;
    else
        std::cout << "❌ Error: Pointers do not match" << std::endl;

    return 0;
}
