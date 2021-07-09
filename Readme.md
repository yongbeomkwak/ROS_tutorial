# ROS_tutorial
- [0. dynamic_reconfigure(.cfg)](http://wiki.ros.org/dynamic_reconfigure/Tutorials/HowToWriteYourFirstCfgFile)

  - cfg 파일 내용

    ```python
    # 패키지명과 노드명은 동일하게 쓰는 것이 좋음. 
    PACKAGE = "dynamic_tutorials" 
    # 패키지명, 노드명, 3rd Parameter(cpp헤더, 파이썬import에 사용됨)
    exit(gen.generate(PACKAGE, "dynamic_tutorials", "Tutorials"))
    
    # 파라미터명, 타입, Level(=0), 설명글, 초기값, MIN, MAX
    gen.add("int_param", int_t, 0, "An Integer parameter", 50,  0, 100)
    ```

  - cfg 파일 실행권한설정

    ```shell
    chmod +x cfg/파일명.cfg 
    ```

    

- [1. dynamic_reconfigure(.cpp)](https://enssionaut.com/board_robotics/1221)

   - .cgf(파이썬 파일) , cpp에서 사용시    XX.cfg 파일 이름일 때 XX +Config.h 로 불러옴  

   - [**dynamic_reconfigure_사용법(cpp).txt**](https://github.com/yongbeomkwak/ROS_tutorial/blob/master/dynamic_reconfigure_사용법(cpp).txt)

       

- [2. dynamic_reconfigure(.py)](http://wiki.ros.org/dynamic_reconfigure/Tutorials/SettingUpDynamicReconfigureForANode%28python%29)

  -  모듈 import

     ```python
     # 기본으로 import 해줘야할 dynamic_reconfigure 패키지의 서버 모듈
     from dynamic_reconfigure.server import Server
     
     # from 패키지명.cfg import 세번째인자Config
     # cfg파일에서 gen.generate 부분의 세번째 인자임
     # exit(gen.generate(PACKAGE, "dynamic_tutorials", "Tutorials"))
     from dynamic_foscar_test.cfg import dynamic_testConfig
     ```

  -  또다른 cfg 파일을 사용할 때 (ex. dynamic_test2.cfg)

     ```python
     # 1) 모듈 import 추가
     from dynamic_tutorials.cfg import dynamic_testConfig, dynamic_test2Config 
     
     # 2) callback 함수 추가
     def callback(config, level):
          rospy.loginfo("Reconfiugre Request: {test1}, {test2}".format(**config))
          return config
     
     def callback2(config, level):
          rospy.loginfo("Reconfiugre Request: {test1}, {test2}".format(**config))
          return config
     
     if __name__ == "__main__":
          rospy.init_node("test", anonymous = False)
             
          # 3) 서버 파라미터 추가
          srv = Server(dynamic_testConfig, callback)
          srv2 = Server(dynamic_test2Config, callback2)
          rospy.spin()
     ```

  -  config 파라미터 사용

     ```python
     def callback(config, level):
          # config.파라미터명 으로 사용
          print(config.test1, config.test2) 
          # 또는 가변형으로 사용가능
          rospy.loginfo("Reconfiugre Request: {test1}, {test2}".format(**config))
          return config
     ```

  -  파이썬 실행 권한 설정

     ```shell
     chmod +x test.py
     ```

     

-  [3. 실행](#)

   1. roscore 실행 (또는 roslaunch로 실행)

   2. 노드 실행 (obstacle_detector라던가, test.py라던가...)

   3. rqt_gui 실행

      - rqt reconfigure 패키지 설치 (아래 명령 안되었을 시)

        ```shell
        sudo apt-get install ros-DISTRO-rqt-reconfigure
        ```

      - rqt_gui 실행 커맨드

        : rqt_gui를 끄지 않으면 계속 서버가 존재하여 값이 남아있게 됨.

        ```shell
        rosrun rqt_gui rqt_gui -s reconfigure
        ```

        ![Screenshot-Reconfigure.png](http://wiki.ros.org/dynamic_reconfigure/Tutorials/SettingUpDynamicReconfigureForANode%28python%29/groovy?action=AttachFile&do=get&target=Screenshot-Reconfigure.png)

