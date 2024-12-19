cd our-chat
sudo nohup ./rebuild.sh > chat_output.log 2>&1 &

cd ..

cd image_service/build
sudo nohup ./image_service > immg_output.log 2>&1 &