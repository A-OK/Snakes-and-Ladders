#ifndef java_lang_Character_H
#define java_lang_Character_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
        class Comparable;
        class String;
        class CharSequence;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class Character : public ::java::lang::Object {
        public:
            enum {
                mid_init$_87fd545a,
                mid_charCount_39c7bd23,
                mid_charValue_54c6a173,
                mid_codePointAt_ec6430eb,
                mid_codePointAt_2fbf15bf,
                mid_codePointAt_6f0bb349,
                mid_codePointBefore_2fbf15bf,
                mid_codePointBefore_ec6430eb,
                mid_codePointBefore_6f0bb349,
                mid_codePointCount_6cc8d7fd,
                mid_codePointCount_6f0bb349,
                mid_compareTo_290588f1,
                mid_compareTo_35927258,
                mid_digit_3108448f,
                mid_digit_d8d154b9,
                mid_equals_290588e2,
                mid_forDigit_d8d154b3,
                mid_getDirectionality_87fd544e,
                mid_getDirectionality_39c7bd28,
                mid_getNumericValue_39c7bd23,
                mid_getNumericValue_87fd5445,
                mid_getType_87fd5445,
                mid_getType_39c7bd23,
                mid_hashCode_54c6a179,
                mid_isDefined_87fd5456,
                mid_isDefined_39c7bd30,
                mid_isDigit_39c7bd30,
                mid_isDigit_87fd5456,
                mid_isHighSurrogate_87fd5456,
                mid_isISOControl_39c7bd30,
                mid_isISOControl_87fd5456,
                mid_isIdentifierIgnorable_39c7bd30,
                mid_isIdentifierIgnorable_87fd5456,
                mid_isJavaIdentifierPart_39c7bd30,
                mid_isJavaIdentifierPart_87fd5456,
                mid_isJavaIdentifierStart_87fd5456,
                mid_isJavaIdentifierStart_39c7bd30,
                mid_isJavaLetter_87fd5456,
                mid_isJavaLetterOrDigit_87fd5456,
                mid_isLetter_87fd5456,
                mid_isLetter_39c7bd30,
                mid_isLetterOrDigit_39c7bd30,
                mid_isLetterOrDigit_87fd5456,
                mid_isLowSurrogate_87fd5456,
                mid_isLowerCase_39c7bd30,
                mid_isLowerCase_87fd5456,
                mid_isMirrored_87fd5456,
                mid_isMirrored_39c7bd30,
                mid_isSpace_87fd5456,
                mid_isSpaceChar_87fd5456,
                mid_isSpaceChar_39c7bd30,
                mid_isSupplementaryCodePoint_39c7bd30,
                mid_isSurrogatePair_37c94822,
                mid_isTitleCase_39c7bd30,
                mid_isTitleCase_87fd5456,
                mid_isUnicodeIdentifierPart_87fd5456,
                mid_isUnicodeIdentifierPart_39c7bd30,
                mid_isUnicodeIdentifierStart_39c7bd30,
                mid_isUnicodeIdentifierStart_87fd5456,
                mid_isUpperCase_39c7bd30,
                mid_isUpperCase_87fd5456,
                mid_isValidCodePoint_39c7bd30,
                mid_isWhitespace_39c7bd30,
                mid_isWhitespace_87fd5456,
                mid_offsetByCodePoints_6cc8d7fd,
                mid_offsetByCodePoints_f453ace9,
                mid_reverseBytes_87fd544f,
                mid_toChars_b4292e99,
                mid_toChars_273c5d2d,
                mid_toCodePoint_37c94831,
                mid_toLowerCase_39c7bd23,
                mid_toLowerCase_87fd544f,
                mid_toString_14c7b5c5,
                mid_toString_7611a535,
                mid_toTitleCase_87fd544f,
                mid_toTitleCase_39c7bd23,
                mid_toUpperCase_39c7bd23,
                mid_toUpperCase_87fd544f,
                mid_valueOf_58724da6,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Character(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Character(const Character& obj) : ::java::lang::Object(obj) {}

            static jbyte COMBINING_SPACING_MARK;
            static jbyte CONNECTOR_PUNCTUATION;
            static jbyte CONTROL;
            static jbyte CURRENCY_SYMBOL;
            static jbyte DASH_PUNCTUATION;
            static jbyte DECIMAL_DIGIT_NUMBER;
            static jbyte DIRECTIONALITY_ARABIC_NUMBER;
            static jbyte DIRECTIONALITY_BOUNDARY_NEUTRAL;
            static jbyte DIRECTIONALITY_COMMON_NUMBER_SEPARATOR;
            static jbyte DIRECTIONALITY_EUROPEAN_NUMBER;
            static jbyte DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR;
            static jbyte DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR;
            static jbyte DIRECTIONALITY_LEFT_TO_RIGHT;
            static jbyte DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING;
            static jbyte DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE;
            static jbyte DIRECTIONALITY_NONSPACING_MARK;
            static jbyte DIRECTIONALITY_OTHER_NEUTRALS;
            static jbyte DIRECTIONALITY_PARAGRAPH_SEPARATOR;
            static jbyte DIRECTIONALITY_POP_DIRECTIONAL_FORMAT;
            static jbyte DIRECTIONALITY_RIGHT_TO_LEFT;
            static jbyte DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC;
            static jbyte DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING;
            static jbyte DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE;
            static jbyte DIRECTIONALITY_SEGMENT_SEPARATOR;
            static jbyte DIRECTIONALITY_UNDEFINED;
            static jbyte DIRECTIONALITY_WHITESPACE;
            static jbyte ENCLOSING_MARK;
            static jbyte END_PUNCTUATION;
            static jbyte FINAL_QUOTE_PUNCTUATION;
            static jbyte FORMAT;
            static jbyte INITIAL_QUOTE_PUNCTUATION;
            static jbyte LETTER_NUMBER;
            static jbyte LINE_SEPARATOR;
            static jbyte LOWERCASE_LETTER;
            static jbyte MATH_SYMBOL;
            static jint MAX_CODE_POINT;
            static jchar MAX_HIGH_SURROGATE;
            static jchar MAX_LOW_SURROGATE;
            static jint MAX_RADIX;
            static jchar MAX_SURROGATE;
            static jchar MAX_VALUE;
            static jint MIN_CODE_POINT;
            static jchar MIN_HIGH_SURROGATE;
            static jchar MIN_LOW_SURROGATE;
            static jint MIN_RADIX;
            static jint MIN_SUPPLEMENTARY_CODE_POINT;
            static jchar MIN_SURROGATE;
            static jchar MIN_VALUE;
            static jbyte MODIFIER_LETTER;
            static jbyte MODIFIER_SYMBOL;
            static jbyte NON_SPACING_MARK;
            static jbyte OTHER_LETTER;
            static jbyte OTHER_NUMBER;
            static jbyte OTHER_PUNCTUATION;
            static jbyte OTHER_SYMBOL;
            static jbyte PARAGRAPH_SEPARATOR;
            static jbyte PRIVATE_USE;
            static jint SIZE;
            static jbyte SPACE_SEPARATOR;
            static jbyte START_PUNCTUATION;
            static jbyte SURROGATE;
            static jbyte TITLECASE_LETTER;
            static ::java::lang::Class *TYPE;
            static jbyte UNASSIGNED;
            static jbyte UPPERCASE_LETTER;

            Character(jchar);

            static jint charCount(jint);
            jchar charValue() const;
            static jint codePointAt(const JArray< jchar > &, jint);
            static jint codePointAt(const ::java::lang::CharSequence &, jint);
            static jint codePointAt(const JArray< jchar > &, jint, jint);
            static jint codePointBefore(const ::java::lang::CharSequence &, jint);
            static jint codePointBefore(const JArray< jchar > &, jint);
            static jint codePointBefore(const JArray< jchar > &, jint, jint);
            static jint codePointCount(const ::java::lang::CharSequence &, jint, jint);
            static jint codePointCount(const JArray< jchar > &, jint, jint);
            jint compareTo(const ::java::lang::Object &) const;
            jint compareTo(const Character &) const;
            static jint digit(jchar, jint);
            static jint digit(jint, jint);
            jboolean equals(const ::java::lang::Object &) const;
            static jchar forDigit(jint, jint);
            static jbyte getDirectionality(jchar);
            static jbyte getDirectionality(jint);
            static jint getNumericValue(jint);
            static jint getNumericValue(jchar);
            static jint getType(jchar);
            static jint getType(jint);
            jint hashCode() const;
            static jboolean isDefined(jchar);
            static jboolean isDefined(jint);
            static jboolean isDigit(jint);
            static jboolean isDigit(jchar);
            static jboolean isHighSurrogate(jchar);
            static jboolean isISOControl(jint);
            static jboolean isISOControl(jchar);
            static jboolean isIdentifierIgnorable(jint);
            static jboolean isIdentifierIgnorable(jchar);
            static jboolean isJavaIdentifierPart(jint);
            static jboolean isJavaIdentifierPart(jchar);
            static jboolean isJavaIdentifierStart(jchar);
            static jboolean isJavaIdentifierStart(jint);
            static jboolean isJavaLetter(jchar);
            static jboolean isJavaLetterOrDigit(jchar);
            static jboolean isLetter(jchar);
            static jboolean isLetter(jint);
            static jboolean isLetterOrDigit(jint);
            static jboolean isLetterOrDigit(jchar);
            static jboolean isLowSurrogate(jchar);
            static jboolean isLowerCase(jint);
            static jboolean isLowerCase(jchar);
            static jboolean isMirrored(jchar);
            static jboolean isMirrored(jint);
            static jboolean isSpace(jchar);
            static jboolean isSpaceChar(jchar);
            static jboolean isSpaceChar(jint);
            static jboolean isSupplementaryCodePoint(jint);
            static jboolean isSurrogatePair(jchar, jchar);
            static jboolean isTitleCase(jint);
            static jboolean isTitleCase(jchar);
            static jboolean isUnicodeIdentifierPart(jchar);
            static jboolean isUnicodeIdentifierPart(jint);
            static jboolean isUnicodeIdentifierStart(jint);
            static jboolean isUnicodeIdentifierStart(jchar);
            static jboolean isUpperCase(jint);
            static jboolean isUpperCase(jchar);
            static jboolean isValidCodePoint(jint);
            static jboolean isWhitespace(jint);
            static jboolean isWhitespace(jchar);
            static jint offsetByCodePoints(const ::java::lang::CharSequence &, jint, jint);
            static jint offsetByCodePoints(const JArray< jchar > &, jint, jint, jint, jint);
            static jchar reverseBytes(jchar);
            static JArray< jchar > toChars(jint);
            static jint toChars(jint, const JArray< jchar > &, jint);
            static jint toCodePoint(jchar, jchar);
            static jint toLowerCase(jint);
            static jchar toLowerCase(jchar);
            ::java::lang::String toString() const;
            static ::java::lang::String toString(jchar);
            static jchar toTitleCase(jchar);
            static jint toTitleCase(jint);
            static jint toUpperCase(jint);
            static jchar toUpperCase(jchar);
            static Character valueOf(jchar);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Character);

        class t_Character {
        public:
            PyObject_HEAD
            Character object;
            static PyObject *wrap_Object(const Character&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
