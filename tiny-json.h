
/*
 * Developed by Rafa Garcia <rafagarcia77@gmail.com>
 *
 * tiny-json.h is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * tiny-json.h is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tiny-json.h.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _TINY_JSON_H_
#define	_TINY_JSON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "tiny-json_config.h"
#include <stdlib.h>

/** @defgroup tinyJson Tiny JSON parser.
  * @{ */

/** Enumeration of codes of supported JSON properties types. */
typedef enum {
    JSON_OBJ, JSON_ARRAY, JSON_TEXT, JSON_BOOLEAN,
    JSON_INTEGER, JSON_REAL, JSON_NULL
} jsonType_t;

/** Structure to handle JSON properties. */
typedef struct json_s {
    struct json_s* sibling;
    char const* name;
    union {
        char const* value;
        struct json_s* child;
    } u;
    jsonType_t type;
} json_t;

/** Parse a string to get a json.
  * @param str String pointer with a JSON object. It will be modified.
  * @param mem Array of json properties to allocate.
  * @param qty Number of elements of mem.
  * @retval Null pointer if any was wrong in the parse process.
  * @retval If the parser process was successfully a valid handler of a json.
  *         This property is always unnamed and its type is JSON_OBJ. */
json_t const* json_create( char* str, json_t mem[], unsigned int qty );

/** Get the name of a json property.
  * @param json A valid handler of a json property.
  * @retval Pointer to null-terminated if property has name.
  * @retval Null pointer if the property is unnamed. */
inline char const* json_getName( json_t const* json );

/** Get the value of a json property.
  * The type of property cannot be JSON_OBJ or JSON_ARRAY.
  * @param json A valid handler of a json property.
  * @return Pointer to null-terminated string with the value. */
inline char const* json_getValue( json_t const* property );

/** Get the type of a json property.
  * @param json A valid handler of a json property.
  * @return The code of type.*/
inline jsonType_t json_getType( json_t const* json );

/** Get the next sibling of a JSON property that is within a JSON object or array.
  * @param json A valid handler of a json property.
  * @retval The handler of the next sibling if found.
  * @retval Null pointer if the json property is the last one. */
inline json_t const* json_getSibling( json_t const* json );

/** Search a property by its name in a JSON object.
  * @param obj A valid handler of a json object. Its type must be JSON_OBJ.
  * @param property The name of property to get.
  * @retval The handler of the json property if found.
  * @retval Null pointer if not found. */
json_t const* json_getProperty( json_t const* obj, char const* property );


/** Search a property by its name in a JSON object and return its value.
  * @param obj A valid handler of a json object. Its type must be JSON_OBJ.
  * @param property The name of property to get.
  * @retval If found a pointer to null-terminated string with the value.
  * @retval Null pointer if not found or it is an array or an object. */
char const* json_getPropertyValue( json_t const* obj, char const* property );

/** Get the first property of a JSON object or array.
  * @param json A valid handler of a json property.
  *             Its type must be JSON_OBJ or JSON_ARRAY.
  * @retval The handler of the first property if there is.
  * @retval Null pointer if the json object has not properties. */
inline json_t const* json_getChild( json_t const* json );

/** Get the value of a json boolean property.
  * @param property A valid handler of a json object. Its type must be JSON_BOOLEAN.
  * @return The value stdbool. */
inline bool json_getBoolean( json_t const* property );

/** Get the value of a json integer property.
  * @param property A valid handler of a json object. Its type must be JSON_INTEGER.
  * @return The value stdint. */
#if TINYJSON_USE_LONG_LONG_INTEGER
inline int64_t json_getInteger( json_t const* property );
#else
inline int32_t json_getInteger( json_t const* property );
#endif

/** Get the value of a json real property.
  * @param property A valid handler of a json object. Its type must be JSON_REAL.
  * @return The value. */
inline double json_getReal( json_t const* property );

/** @ } */

#ifdef __cplusplus
}
#endif

#endif	/* _TINY_JSON_H_ */
