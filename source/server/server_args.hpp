//  server arguments
//  Copyright (C) 2009 Tim Blechmann
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; see the file COPYING.  If not, write to
//  the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
//  Boston, MA 02111-1307, USA.

#ifndef SERVER_SERVER_ARGS_HPP
#define SERVER_SERVER_ARGS_HPP

#include <stdint.h>
#include <string>
#include <vector>
#include <memory>

namespace nova
{

class server_arguments
{
    server_arguments(int argc, char * argv[]);

public:
    static void initialize(int argc, char * argv[])
    {
        instance_.reset(new server_arguments(argc, argv));
    }

    static server_arguments const & instance(void)
    {
        return *instance_;
    }

    uint32_t udp_port, tcp_port;
    uint32_t control_busses, audio_busses;
    uint32_t blocksize, samplerate;
    uint32_t buffers, max_nodes, max_synthdefs;

    uint32_t rt_pool_size;
    uint32_t wires, randomseeds;

    uint16_t load_synthdefs;
    int16_t verbosity;
    std::string hw_name;
    bool memory_locking;
    uint16_t threads;

    std::vector<std::string> ugen_paths, restrict_paths;

    uint16_t input_channels, output_channels;

private:
    static std::auto_ptr<server_arguments> instance_;
};

} /* namespace nova */

#endif /* SERVER_SERVER_ARGS_HPP */
