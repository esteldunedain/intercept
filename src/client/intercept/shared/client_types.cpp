#include "client_types.hpp"
#include "client\client.hpp"
#include "shared\functions.hpp"

namespace intercept {
    namespace types {

        internal_object::internal_object() {}
        internal_object::internal_object(const rv_game_value &value_) : game_value(value_) {}
        internal_object::internal_object(const game_value & value_) : game_value(value_.rv_data)
        {

        }
        internal_object::internal_object(const internal_object & copy_)
        {
            copy(copy_);
        }
        internal_object::internal_object(internal_object && move_) : game_value(move_) {};

        internal_object & internal_object::operator=(internal_object && move_)
        {
            if (this == &move_)
                return *this;
            if (rv_data.data)
                _free();
            rv_data.__vptr = move_.rv_data.__vptr;
            rv_data.data = move_.rv_data.data;
            move_.rv_data.data = nullptr;
            return *this;
        }

        internal_object & internal_object::operator=(const internal_object & copy_)
        {
            copy(copy_);
            return *this;
        }

        internal_object::operator game_value*()
        {
            return (game_value *)this;
        }

        internal_object::operator game_value*() const
        {
            return (game_value *)this;
        }

        bool internal_object::operator<(const internal_object& compare_) const {
            return ((game_data_object *)rv_data.data)->object < ((game_data_object *)compare_.rv_data.data)->object;
        }

        bool internal_object::operator>(const internal_object& compare_) const {
            return ((game_data_object *)rv_data.data)->object > ((game_data_object *)compare_.rv_data.data)->object;
        }

        bool internal_object::is_null()
        {
            uintptr_t data = (uintptr_t)(rv_data.data);
            uintptr_t data_1 = data + 12;
            uintptr_t data_2 = *(uintptr_t *)data_1;
            if (data_2) {
                uintptr_t data_3 = data_2 + 4;
                uintptr_t val = *(uintptr_t *)data_3;
                return !val;
            }
            else {
                return true;
            }
        }



#define RV_GENERIC_OBJECT_DEF(type)         type##::##type##() {}\
        type##::##type##(const rv_game_value &value_) : internal_object(value_) {}\
        type##::##type##(const game_value & value_) : internal_object(value_.rv_data) {}\
        type##::##type##(const type &copy_) {\
            copy(copy_);\
        }\
        type##::##type##(type && move_) : internal_object(std::move(move_)) {}\
        type & type##::operator=(type && move_) {\
            if (this == &move_)\
            return *this;\
            if (rv_data.data)\
                _free();\
            rv_data.__vptr = move_.rv_data.__vptr;\
            rv_data.data = move_.rv_data.data;\
            move_.rv_data.data = nullptr;\
            return *this;\
        }\
        type & type##::operator=(const type & copy_)\
        {\
            copy(copy_);\
            return *this;\
        }

        RV_GENERIC_OBJECT_DEF(object)

        RV_GENERIC_OBJECT_DEF(group)

        RV_GENERIC_OBJECT_DEF(code)

        RV_GENERIC_OBJECT_DEF(config)

        RV_GENERIC_OBJECT_DEF(control)

        RV_GENERIC_OBJECT_DEF(display)

        RV_GENERIC_OBJECT_DEF(location)

        RV_GENERIC_OBJECT_DEF(script)

        RV_GENERIC_OBJECT_DEF(side)

        RV_GENERIC_OBJECT_DEF(rv_text)

        RV_GENERIC_OBJECT_DEF(team_member)

        RV_GENERIC_OBJECT_DEF(rv_namespace)

        RV_GENERIC_OBJECT_DEF(task)
    }
}
