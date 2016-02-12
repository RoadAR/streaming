Vagrant.configure(2) do |config|
  config.vm.box = "vlc_streamer"
  config.vm.synced_folder ".", "/vagrant"

  config.vm.network "forwarded_port", guest: 5554, host: 5554

  config.vm.provider "virtualbox" do |v|
    v.memory = 1024
    v.cpus = 1
  end
end
