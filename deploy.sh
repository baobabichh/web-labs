cd our-chat
nohup .rebuild.sh > chat_output.log 2>&1 &

cd ..

cd image_service/build
nohup ..image_service > immg_output.log 2>&1 &