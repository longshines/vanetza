#include <vanetza/security/openssl_wrapper.hpp>
#include <vanetza/security/public_key.hpp>
#include <cassert>

namespace vanetza
{
namespace security
{
namespace openssl
{

void check(bool valid)
{
    if (!valid) {
        throw Exception();
    }
}

Exception::Exception() : Exception(ERR_get_error())
{
}

Exception::Exception(code_type err) :
    std::runtime_error(ERR_reason_error_string(err))
{
}

BigNumber::BigNumber()
{
    BN_init(&bignum);
}

BigNumber::BigNumber(const uint8_t* arr, std::size_t len) : BigNumber()
{
    BN_bin2bn(arr, len, &bignum);
}

BigNumber::~BigNumber()
{
    BN_clear_free(&bignum);
}

BigNumberContext::BigNumberContext() : ctx(BN_CTX_new())
{
    check(ctx != nullptr);
    BN_CTX_start(ctx);
}

BigNumberContext::~BigNumberContext()
{
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
}

Point::Point(const EC_GROUP* group) : point(EC_POINT_new(group))
{
    check(point != nullptr);
}

Point::~Point()
{
    EC_POINT_free(point);
}

Signature::Signature(ECDSA_SIG* sig) :
    signature(sig)
{
    check(signature);
}

Signature::Signature(const ByteBuffer& sig) : signature(ECDSA_SIG_new())
{
    const std::size_t size = field_size(PublicKeyAlgorithm::Ecdsa_Nistp256_With_Sha256);
    assert(sig.size() == 2 * size);
    BN_bin2bn(sig.data(), size, signature->r);
    BN_bin2bn(sig.data() + size, size, signature->s);
}

Signature::~Signature()
{
    ECDSA_SIG_free(signature);
}

Key::Key() : eckey(EC_KEY_new())
{
    check(eckey);
}

Key::Key(int nid) : eckey(EC_KEY_new_by_curve_name(nid))
{
    check(eckey);
}

Key::~Key()
{
    EC_KEY_free(eckey);
}

} // namespace openssl
} // namespace security
} // namespace vanetza