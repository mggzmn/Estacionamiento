require "serialport"
require "twitter" 
#params for serial port
port_str = "/dev/ttyACM4"  #may be different for you
baud_rate = 9600
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE

sp = SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)

#params for twitter
client = Twitter::REST::Client.new do |config|
  config.consumer_key        = "g5OpwqdNSBU0sPxAUmnyGDKVo"
  config.consumer_secret     = "xBhnxmoiTVmNpjCdlCCWuKIF8q8yH4XuqJLfstHqlBBMLMjBJA"
  config.access_token        = "2683547622-XQkJy6cve0QBYtDmJ1Y2m6Po5zkhUuxvc6FiGoE"
  config.access_token_secret = "7UEm2QzPElFVSMEkR1PMlC5ORxNFjFgUUD7RI24WfIyRp"
end

#just read forever
while true do
   while (i = sp.gets) do       # see note 2
      puts i
      client.update("Capacidad Disponible : #{i}")
    end
end
 
sp.close
