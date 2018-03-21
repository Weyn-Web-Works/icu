// © 2018 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html

#include "unicode/utypes.h"

#if !UCONFIG_NO_FORMATTING && !UPRV_INCOMPLETE_CPP11_SUPPORT
#ifndef __SOURCE_NUMPARSE_VALIDATORS_H__
#define __SOURCE_NUMPARSE_VALIDATORS_H__

#include "numparse_types.h"
#include "numparse_unisets.h"

U_NAMESPACE_BEGIN namespace numparse {
namespace impl {


class ValidationMatcher : public NumberParseMatcher {
  public:
    bool match(StringSegment&, ParsedNumber&, UErrorCode&) const U_OVERRIDE {
        // No-op
        return false;
    }

    bool smokeTest(const StringSegment&) const U_OVERRIDE {
        // No-op
        return false;
    }

    void postProcess(ParsedNumber& result) const U_OVERRIDE = 0;
};


class RequireAffixValidator : public ValidationMatcher, public UMemory {
  public:
    void postProcess(ParsedNumber& result) const U_OVERRIDE;

    UnicodeString toString() const U_OVERRIDE;
};


class RequireCurrencyValidator : public ValidationMatcher, public UMemory {
  public:
    void postProcess(ParsedNumber& result) const U_OVERRIDE;

    UnicodeString toString() const U_OVERRIDE;
};


class RequireDecimalSeparatorValidator : public ValidationMatcher, public UMemory {
  public:
    RequireDecimalSeparatorValidator() = default;  // leaves instance in valid but undefined state

    RequireDecimalSeparatorValidator(bool patternHasDecimalSeparator);

    void postProcess(ParsedNumber& result) const U_OVERRIDE;

    UnicodeString toString() const U_OVERRIDE;

  private:
    bool fPatternHasDecimalSeparator;
};


class RequireExponentValidator : public ValidationMatcher, public UMemory {
  public:
    void postProcess(ParsedNumber& result) const U_OVERRIDE;

    UnicodeString toString() const U_OVERRIDE;
};


class RequireNumberValidator : public ValidationMatcher, public UMemory {
  public:
    void postProcess(ParsedNumber& result) const U_OVERRIDE;

    UnicodeString toString() const U_OVERRIDE;
};


} // namespace impl
} // namespace numparse
U_NAMESPACE_END

#endif //__SOURCE_NUMPARSE_VALIDATORS_H__
#endif /* #if !UCONFIG_NO_FORMATTING */
