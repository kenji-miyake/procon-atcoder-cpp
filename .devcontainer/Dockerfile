#-------------------------------------------------------------------------------------------------------------
# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License. See https://go.microsoft.com/fwlink/?linkid=2090316 for license information.
#-------------------------------------------------------------------------------------------------------------

FROM debian:10

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# Configure apt and install packages
RUN apt-get update \
  && apt-get -y install --no-install-recommends apt-utils 2>&1 \
  #
  # Verify vim, jq, git, tig, process tools, lsb-release (useful for CLI installs) installed
  && apt-get -y install vim jq git tig procps lsb-release \
  #
  # Install C++ tools
  && apt-get -y install build-essential cmake cppcheck valgrind libtinfo5 \
  #
  # Install Python and helper tools
  && apt-get -y install python3-pip \
  && ln -sf /usr/bin/python3 /usr/bin/python && ln -sf /usr/bin/pip3 /usr/bin/pip \
  && pip install -U pip \
  && pip install online-judge-tools atcoder-tools git+https://github.com/kenji-miyake/atcoder-helper \
  #
  # Clean up
  && apt-get autoremove -y \
  && apt-get clean -y \
  && rm -rf /var/lib/apt/lists/*

# Switch back to dialog for any ad-hoc use of apt-get
ENV DEBIAN_FRONTEND=dialog
