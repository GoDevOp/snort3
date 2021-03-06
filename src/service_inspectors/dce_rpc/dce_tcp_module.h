//--------------------------------------------------------------------------
// Copyright (C) 2016-2016 6isco and/or its affiliates. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License Version 2 as published
// by the Free Software Foundation.  You may not use, modify or distribute
// this program under any other version of the GNU General Public License.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//--------------------------------------------------------------------------
//
// dce_tcp_module.h author Rashmi Pitre <rrp@cisco.com>

#ifndef DCE2_TCP_MODULE_H
#define DCE2_TCP_MODULE_H

#include "dce_common.h"
#include "framework/module.h"

struct SnortConfig;

struct dce2TcpProtoConf
{
    dce2CommonProtoConf common;
    uint16_t co_reassemble_threshold;
};

class Dce2TcpModule : public Module
{
public:
    Dce2TcpModule();

    bool set(const char*, Value&, SnortConfig*) override;

    unsigned get_gid() const override
    {
        return GID_DCE2;
    }

    const RuleMap* get_rules() const override;
    const PegInfo* get_pegs() const override;
    PegCount* get_counts() const override;
    ProfileStats* get_profile(unsigned, const char*&, const char*&) const override;
    void get_data(dce2TcpProtoConf&);

private:
    dce2TcpProtoConf config;
};

void print_dce2_tcp_conf(dce2TcpProtoConf& config);

#endif

