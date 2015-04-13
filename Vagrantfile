# -*- mode: ruby -*-
# vi: set ft=ruby :


# I got the VM image from:
#     https://www.modern.ie/
# Once you import one of those appliances you can package it for vagrant with:
#     vagrant package --base "IE11 - Win10" --output windows.box
# Once you have it pacakged for vagrant you can add it to vagrant with:
#     vagrant box add windows.box --name windows10-ie11

Vagrant.configure(2) do |config|
  config.vm.box = "windows10-ie11"
  config.vm.network :private_network, ip: "10.13.37.11"
  config.vm.provider "virtualbox" do |v|
    v.gui = true
    v.customize ["modifyvm", :id, "--memory", 4096]
    v.customize ["modifyvm", :id, "--vram", 128]
    v.customize ["modifyvm", :id, "--accelerate3d", "on"]
  end
end
