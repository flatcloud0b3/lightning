/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the .csv file it was generated from. */
/* Original template can be found at tools/gen/impl_template */

#include <closingd/closingd_wiregen.h>
#include <assert.h>
#include <ccan/array_size/array_size.h>
#include <ccan/mem/mem.h>
#include <ccan/tal/str/str.h>
#include <common/utils.h>
#include <stdio.h>

#ifndef SUPERVERBOSE
#define SUPERVERBOSE(...)
#endif


const char *closingd_wire_name(int e)
{
	static char invalidbuf[sizeof("INVALID ") + STR_MAX_CHARS(e)];

	switch ((enum closingd_wire)e) {
	case WIRE_CLOSINGD_INIT: return "WIRE_CLOSINGD_INIT";
	case WIRE_CLOSINGD_RECEIVED_SIGNATURE: return "WIRE_CLOSINGD_RECEIVED_SIGNATURE";
	case WIRE_CLOSINGD_RECEIVED_SIGNATURE_REPLY: return "WIRE_CLOSINGD_RECEIVED_SIGNATURE_REPLY";
	case WIRE_CLOSINGD_COMPLETE: return "WIRE_CLOSINGD_COMPLETE";
	}

	snprintf(invalidbuf, sizeof(invalidbuf), "INVALID %i", e);
	return invalidbuf;
}

bool closingd_wire_is_defined(u16 type)
{
	switch ((enum closingd_wire)type) {
	case WIRE_CLOSINGD_INIT:;
	case WIRE_CLOSINGD_RECEIVED_SIGNATURE:;
	case WIRE_CLOSINGD_RECEIVED_SIGNATURE_REPLY:;
	case WIRE_CLOSINGD_COMPLETE:;
	      return true;
	}
	return false;
}





/* WIRE: CLOSINGD_INIT */
/* Begin!  (passes peer fd */
u8 *towire_closingd_init(const tal_t *ctx, const struct chainparams *chainparams, const struct per_peer_state *pps, const struct channel_id *channel_id, const struct bitcoin_txid *funding_txid, u16 funding_txout, struct amount_sat funding_satoshi, const struct pubkey *local_fundingkey, const struct pubkey *remote_fundingkey, enum side opener, struct amount_sat local_sat, struct amount_sat remote_sat, struct amount_sat our_dust_limit, u32 min_feerate_perksipa, u32 preferred_feerate_perksipa, struct amount_sat fee_limit_satoshi, const u8 *local_scriptpubkey, const u8 *remote_scriptpubkey, u64 fee_negotiation_step, u8 fee_negotiation_step_unit, bool dev_fast_gossip, const struct bitcoin_outpoint *shutdown_wrong_funding)
{
	u16 local_scriptpubkey_len = tal_count(local_scriptpubkey);
	u16 remote_scriptpubkey_len = tal_count(remote_scriptpubkey);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CLOSINGD_INIT);
	towire_chainparams(&p, chainparams);
	towire_per_peer_state(&p, pps);
	towire_channel_id(&p, channel_id);
	towire_bitcoin_txid(&p, funding_txid);
	towire_u16(&p, funding_txout);
	towire_amount_sat(&p, funding_satoshi);
	towire_pubkey(&p, local_fundingkey);
	towire_pubkey(&p, remote_fundingkey);
	towire_side(&p, opener);
	towire_amount_sat(&p, local_sat);
	towire_amount_sat(&p, remote_sat);
	towire_amount_sat(&p, our_dust_limit);
	towire_u32(&p, min_feerate_perksipa);
	towire_u32(&p, preferred_feerate_perksipa);
	towire_amount_sat(&p, fee_limit_satoshi);
	towire_u16(&p, local_scriptpubkey_len);
	towire_u8_array(&p, local_scriptpubkey, local_scriptpubkey_len);
	towire_u16(&p, remote_scriptpubkey_len);
	towire_u8_array(&p, remote_scriptpubkey, remote_scriptpubkey_len);
	towire_u64(&p, fee_negotiation_step);
	towire_u8(&p, fee_negotiation_step_unit);
	towire_bool(&p, dev_fast_gossip);
	if (!shutdown_wrong_funding)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_bitcoin_outpoint(&p, shutdown_wrong_funding);
	}

	return memcheck(p, tal_count(p));
}
bool fromwire_closingd_init(const tal_t *ctx, const void *p, const struct chainparams **chainparams, struct per_peer_state **pps, struct channel_id *channel_id, struct bitcoin_txid *funding_txid, u16 *funding_txout, struct amount_sat *funding_satoshi, struct pubkey *local_fundingkey, struct pubkey *remote_fundingkey, enum side *opener, struct amount_sat *local_sat, struct amount_sat *remote_sat, struct amount_sat *our_dust_limit, u32 *min_feerate_perksipa, u32 *preferred_feerate_perksipa, struct amount_sat *fee_limit_satoshi, u8 **local_scriptpubkey, u8 **remote_scriptpubkey, u64 *fee_negotiation_step, u8 *fee_negotiation_step_unit, bool *dev_fast_gossip, struct bitcoin_outpoint **shutdown_wrong_funding)
{
	u16 local_scriptpubkey_len;
	u16 remote_scriptpubkey_len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CLOSINGD_INIT)
		return false;
 	fromwire_chainparams(&cursor, &plen, chainparams);
 	*pps = fromwire_per_peer_state(ctx, &cursor, &plen);
 	fromwire_channel_id(&cursor, &plen, channel_id);
 	fromwire_bitcoin_txid(&cursor, &plen, funding_txid);
 	*funding_txout = fromwire_u16(&cursor, &plen);
 	*funding_satoshi = fromwire_amount_sat(&cursor, &plen);
 	fromwire_pubkey(&cursor, &plen, local_fundingkey);
 	fromwire_pubkey(&cursor, &plen, remote_fundingkey);
 	*opener = fromwire_side(&cursor, &plen);
 	*local_sat = fromwire_amount_sat(&cursor, &plen);
 	*remote_sat = fromwire_amount_sat(&cursor, &plen);
 	*our_dust_limit = fromwire_amount_sat(&cursor, &plen);
 	*min_feerate_perksipa = fromwire_u32(&cursor, &plen);
 	*preferred_feerate_perksipa = fromwire_u32(&cursor, &plen);
 	*fee_limit_satoshi = fromwire_amount_sat(&cursor, &plen);
 	local_scriptpubkey_len = fromwire_u16(&cursor, &plen);
 	// 2nd case local_scriptpubkey
	*local_scriptpubkey = local_scriptpubkey_len ? tal_arr(ctx, u8, local_scriptpubkey_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *local_scriptpubkey, local_scriptpubkey_len);
 	remote_scriptpubkey_len = fromwire_u16(&cursor, &plen);
 	// 2nd case remote_scriptpubkey
	*remote_scriptpubkey = remote_scriptpubkey_len ? tal_arr(ctx, u8, remote_scriptpubkey_len) : NULL;
	fromwire_u8_array(&cursor, &plen, *remote_scriptpubkey, remote_scriptpubkey_len);
 	*fee_negotiation_step = fromwire_u64(&cursor, &plen);
 	*fee_negotiation_step_unit = fromwire_u8(&cursor, &plen);
 	*dev_fast_gossip = fromwire_bool(&cursor, &plen);
 	if (!fromwire_bool(&cursor, &plen))
		*shutdown_wrong_funding = NULL;
	else {
		*shutdown_wrong_funding = tal(ctx, struct bitcoin_outpoint);
		fromwire_bitcoin_outpoint(&cursor, &plen, *shutdown_wrong_funding);
	}
	return cursor != NULL;
}

/* WIRE: CLOSINGD_RECEIVED_SIGNATURE */
/* We received an offer */
u8 *towire_closingd_received_signature(const tal_t *ctx, const struct bitcoin_signature *signature, const struct bitcoin_tx *tx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CLOSINGD_RECEIVED_SIGNATURE);
	towire_bitcoin_signature(&p, signature);
	towire_bitcoin_tx(&p, tx);

	return memcheck(p, tal_count(p));
}
bool fromwire_closingd_received_signature(const tal_t *ctx, const void *p, struct bitcoin_signature *signature, struct bitcoin_tx **tx)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CLOSINGD_RECEIVED_SIGNATURE)
		return false;
 	fromwire_bitcoin_signature(&cursor, &plen, signature);
 	*tx = fromwire_bitcoin_tx(ctx, &cursor, &plen);
	return cursor != NULL;
}

/* WIRE: CLOSINGD_RECEIVED_SIGNATURE_REPLY */
u8 *towire_closingd_received_signature_reply(const tal_t *ctx, const struct bitcoin_txid *closing_txid)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CLOSINGD_RECEIVED_SIGNATURE_REPLY);
	towire_bitcoin_txid(&p, closing_txid);

	return memcheck(p, tal_count(p));
}
bool fromwire_closingd_received_signature_reply(const void *p, struct bitcoin_txid *closing_txid)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CLOSINGD_RECEIVED_SIGNATURE_REPLY)
		return false;
 	fromwire_bitcoin_txid(&cursor, &plen, closing_txid);
	return cursor != NULL;
}

/* WIRE: CLOSINGD_COMPLETE */
/* Negotiations complete */
u8 *towire_closingd_complete(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CLOSINGD_COMPLETE);

	return memcheck(p, tal_count(p));
}
bool fromwire_closingd_complete(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CLOSINGD_COMPLETE)
		return false;
	return cursor != NULL;
}
// SHA256STAMP:961ca5ceef03f911684ba0e7863d69993e692b9b418108e6038a567cb7cc7b3e
