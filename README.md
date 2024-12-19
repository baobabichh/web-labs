# This is web chat project
You can easily make friends here and chat with friends.
Have fun =)

# Link
http://104.248.137.89:50505/index.html

# To setup project run
./prebuild.sh

# To rebuild project run
./rebuild.sh

# Deploy to prod
nohup ./our-chat/build/rebuild.sh > output.log 2>&1 &
nohup ./image_service/build/image_service > output.log 2>&1 &
