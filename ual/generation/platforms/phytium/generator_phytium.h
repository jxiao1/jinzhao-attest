#ifndef UAL_GENERATION_PLATFORMS_CSV_UNTRUSTED_GENERATOR_PHYTIUM_H_
#define UAL_GENERATION_PLATFORMS_CSV_UNTRUSTED_GENERATOR_PHYTIUM_H_

#include <map>
#include <memory>
#include <string>

#include "attestation/platforms/csv.h"

#include "attestation/generation/core/generator_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHYTIUM_ATTESTATION_USER_DATA_SIZE 64

#ifdef __cplusplus
}
#endif

namespace kubetee {
namespace attestation {

using kubetee::UnifiedAttestationReport;

// AttestationGeneratorPhytium for generating the attestation report
// for phytium Trustzone TEE instance
class AttestationGeneratorPhytium : public AttestationGeneratorInterface {
 public:
  TeeErrorCode Initialize(const std::string& tee_identity) override;
  TeeErrorCode CreateBgcheckReport(const UaReportGenerationParameters& param,
                                   UnifiedAttestationReport* report) override;
  TeeErrorCode CreatePassportReport(const UaReportGenerationParameters& param,
                                    UnifiedAttestationReport* report) override;
  TeeErrorCode VerifySubReportsTrusted(
      const kubetee::UnifiedAttestationAuthReports& auth_reports,
      const kubetee::UnifiedAttestationPolicy& policy,
      std::string* results_json) override;

 private:
  // internal functions
  TeeErrorCode GetQuote(const UaReportGenerationParameters& param,
                        std::string* pquote_b64);
};

}  // namespace attestation
}  // namespace kubetee

#endif  // UAL_GENERATION_PLATFORMS_CSV_UNTRUSTED_GENERATOR_PHYTIUM_H_
