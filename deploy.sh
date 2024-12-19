cd our-chat
sudo nohup ./rebuild.sh > chat_output.log 

cd ..

cd image_service/build
sudo nohup ./image_service > immg_output.log