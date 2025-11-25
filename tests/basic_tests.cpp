#include "database.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

// Simple helper to check conditions.
// If cond is false, we throw an exception with the given message.
void assert_true(bool cond, const std::string &message) {
    if (!cond) {
        throw std::runtime_error("Test failed: " + message);
    }
}

void test_set_and_get() {
    Database db;

    db.set("name", "shreshth");

    std::string value;
    bool found = db.get("name", value);

    assert_true(found, "GET should return true for existing key");
    assert_true(value == "shreshth", "Value for 'name' should be 'shreshth'");
}

void test_get_missing_key() {
    Database db;

    std::string value;
    bool found = db.get("missing", value);

    assert_true(!found, "GET should return false for missing key");
}

void test_del() {
    Database db;

    db.set("k1", "v1");
    std::size_t erased1 = db.del("k1");
    std::size_t erased2 = db.del("k1");

    assert_true(erased1 == 1, "DEL should return 1 when key existed");
    assert_true(erased2 == 0, "DEL should return 0 when key no longer exists");
}

int main() {
    try {
        test_set_and_get();
        test_get_missing_key();
        test_del();
        std::cout << "All tests passed.\n";
        return 0; // success
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return 1; // failure
    }
}
