#! /bin/bash

# ===============修改podspec的版本号===========================

CoreName="NPCore"
PodName="NoxPay"

echo "\n🔥当前版本号："
# 读取plist中的版本号
srcVer=$(/usr/libexec/PlistBuddy -c "Print CFBundleShortVersionString" ./$CoreName.framework/Info.plist)
echo "\n🔥版本号 = " "$srcVer"

# ===============验证语法============================
# 语法检查的原命令
srcCommand="pod spec lint $PodName.podspec"
# push的原命令
pushCommand="pod trunk push $PodName.podspec"
# 附加命令参数：--skip-import-validation
subCommand="--skip-import-validation --allow-warnings"
echo "\n🔥是否附加--skip-import-validation参数[y/n]"
read flag
if [[ "$flag" == "y" ]]
then
    srcCommand="$srcCommand $subCommand"
    pushCommand="$pushCommand $subCommand"
fi

echo "\n🔥开始验证podspec文件语法"
# 声明命令执行结果
checkRes=`$srcCommand`
checkKey="$PodName.podspec passed validation."

echo "$checkRes"

if [[ $checkRes =~ $checkKey ]]
then
    # 包含
    echo "\n\n🔥验证通过，开始上传pod..."
    
# ===============正式上传============================

    pushRes=`$pushCommand`
    # 打印上传结果
    echo "\n🔥$pushRes\n\n"
    # 根据上传结果判断是否继续
    echo "🔥是否继续[y/n]"
    read stillContinue
    if [[ "$stillContinue" == "y" ]]
    then

# ===============重置索引============================

        echo "\n🔥开始setup\n"
        pod setup
        echo "\n🔥开始删除原索引\n"
        rm ~/Library/Caches/CocoaPods/search_index.json
#        echo "\n🔥开始第一次search\n\n"
#        searchRes1=`pod search $PodName`
#        echo "$searchRes1"
        echo "\n🔥开始pod repo update\n\n"
        repoUpdateRes=`pod repo update`
        echo "$repoUpdateRes"
        echo "\n🔥开始search\n\n"
        searchRes2=`pod search $PodName`
        echo "$searchRes2"
    fi

else
    # 不包含
    echo "\n\n🔥验证未通过"
fi



